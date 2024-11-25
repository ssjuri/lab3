use std::fs;
use std::path::{Path, PathBuf};

fn list_dir_recursive(path: &Path, indent: &str) {
    // 디렉토리 내의 항목들을 읽어옴
    match fs::read_dir(path) {
        Ok(entries) => {
            for entry in entries {
                match entry {
                    Ok(entry) => {
                        let entry_path = entry.path();
                        if entry_path.is_dir() {
                            // 디렉토리인 경우
                            println!("{}{}", indent, entry_path.display());
                            // 재귀적으로 하위 디렉토리 탐색
                            list_dir_recursive(&entry_path, &format!("{}    ", indent));
                        } else {
                            // 파일인 경우
                            println!("{}{}", indent, entry_path.display());
                        }
                    }
                    Err(e) => println!("Error reading entry: {}", e),
                }
            }
        }
        Err(e) => println!("Error reading directory '{}': {}", path.display(), e),
    }
}

fn main() {
    // 사용자로부터 디렉토리 경로 입력 받기
    let mut input = String::new();
    println!("디렉토리 경로를 입력하세요:");
    std::io::stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    // WSL 환경에서 경로 변환 (Windows 경로 -> Linux 경로)
    let path_str = if input.starts_with("C:/") {
        input.replace("C:/", "/mnt/c/")  // WSL 경로 형식으로 변경
    } else {
        input.to_string()  // 다른 경로는 그대로 사용
    };

    let path = Path::new(&path_str);
    
    if path.is_dir() {
        // 디렉토리일 경우, 재귀적으로 리스트 출력
        list_dir_recursive(path, "");
    } else {
        println!("{}는 유효한 디렉토리가 아닙니다.", path.display());
    }
}

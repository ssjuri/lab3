use std::fs;
use std::io::{self, Write};
use std::path::Path;

fn main() {
    // 1. 디렉토리 생성
    let dir_path = "example_dir";
    if let Err(e) = fs::create_dir(dir_path) {
        println!("디렉토리를 생성할 수 없습니다: {}", e);
    } else {
        println!("디렉토리 '{}' 생성 완료!", dir_path);
    }

    // 2. 파일 생성 및 내용 쓰기
    let file_path = format!("{}/example_file.txt", dir_path);
    let mut file = match fs::File::create(&file_path) {
        Ok(f) => f,
        Err(e) => {
            println!("파일을 생성할 수 없습니다: {}", e);
            return;
        }
    };
    if let Err(e) = writeln!(file, "Hello, Rust! 파일 및 디렉토리 작업!") {
        println!("파일에 데이터를 쓸 수 없습니다: {}", e);
    } else {
        println!("파일 '{}' 생성 및 데이터 쓰기 완료!", file_path);
    }

    // 3. 파일 읽기
    match fs::read_to_string(&file_path) {
        Ok(content) => println!("파일 내용: {}", content),
        Err(e) => println!("파일을 읽을 수 없습니다: {}", e),
    }

    // 4. 디렉토리 내부 파일 목록 출력
    println!("디렉토리 '{}' 내부 파일 목록:", dir_path);
    match fs::read_dir(dir_path) {
        Ok(entries) => {
            for entry in entries {
                if let Ok(entry) = entry {
                    println!("- {}", entry.path().display());
                }
            }
        }
        Err(e) => println!("디렉토리를 읽을 수 없습니다: {}", e),
    }

    // 5. 파일 이름 변경
    let new_file_path = format!("{}/renamed_file.txt", dir_path);
    if let Err(e) = fs::rename(&file_path, &new_file_path) {
        println!("파일 이름을 변경할 수 없습니다: {}", e);
    } else {
        println!("파일 이름이 '{}'에서 '{}'로 변경되었습니다!", file_path, new_file_path);
    }

    // 6. 파일 삭제
    if let Err(e) = fs::remove_file(&new_file_path) {
        println!("파일을 삭제할 수 없습니다: {}", e);
    } else {
        println!("파일 '{}' 삭제 완료!", new_file_path);
    }

    // 7. 디렉토리 삭제
    if let Err(e) = fs::remove_dir(dir_path) {
        println!("디렉토리를 삭제할 수 없습니다: {}", e);
    } else {
        println!("디렉토리 '{}' 삭제 완료!", dir_path);
    }
}

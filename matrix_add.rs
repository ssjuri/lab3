use std::io;

fn main() {
    // 사용자 입력을 위한 버퍼
    let mut input = String::new();

    // 행렬의 크기 입력 받기
    println!("첫 번째 행렬의 행(row)과 열(column) 크기를 입력하세요 (예: 2 3):");
    io::stdin().read_line(&mut input).unwrap();
    let dims1: Vec<usize> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    input.clear();

    println!("두 번째 행렬의 행(row)과 열(column) 크기를 입력하세요 (예: 2 3):");
    io::stdin().read_line(&mut input).unwrap();
    let dims2: Vec<usize> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    input.clear();

    // 행렬 크기 확인
    if dims1 != dims2 {
        println!("행렬 크기가 다릅니다. 두 행렬은 동일한 크기여야 합니다.");
        return;
    }

    let rows = dims1[0];
    let cols = dims1[1];

    // 첫 번째 행렬 입력 받기
    println!("첫 번째 행렬의 요소를 입력하세요 (공백으로 구분):");
    let mut matrix1 = Vec::new();
    for _ in 0..rows {
        io::stdin().read_line(&mut input).unwrap();
        let row: Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        if row.len() != cols {
            println!("입력 오류: 열의 개수가 일치하지 않습니다.");
            return;
        }
        matrix1.push(row);
        input.clear();
    }

    // 두 번째 행렬 입력 받기
    println!("두 번째 행렬의 요소를 입력하세요 (공백으로 구분):");
    let mut matrix2 = Vec::new();
    for _ in 0..rows {
        io::stdin().read_line(&mut input).unwrap();
        let row: Vec<i32> = input
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        if row.len() != cols {
            println!("입력 오류: 열의 개수가 일치하지 않습니다.");
            return;
        }
        matrix2.push(row);
        input.clear();
    }

    // 행렬 덧셈
    let mut result = Vec::new();
    for i in 0..rows {
        let mut row = Vec::new();
        for j in 0..cols {
            row.push(matrix1[i][j] + matrix2[i][j]);
        }
        result.push(row);
    }

    // 결과 출력
    println!("행렬 덧셈 결과:");
    for row in result {
        println!("{:?}", row);
    }
}

#include <iostream>
#include <string>

using namespace std;

// 학생 정보를 저장할 구조체
struct Student {
    string name;
    float midterm;
    float final;
};

// 트리 노드 구조체
struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;
};

// 트리에 학생 추가하는 함수
TreeNode* insert(TreeNode* node, Student student) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode;
        newNode->student = student;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (student.name < node->student.name) {
        node->left = insert(node->left, student);
    } else {
        node->right = insert(node->right, student);
    }
    return node;
}

// 트리를 중위 순회하면서 학생 정보 출력하는 함수
void inorder(TreeNode* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << "이름: " << node->student.name 
             << ", 중간 점수: " << node->student.midterm 
             << ", 기말 점수: " << node->student.final << endl;
        inorder(node->right);
    }
}

// 메모리 해제 함수
void freeTree(TreeNode* node) {
    if (node != nullptr) {
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
}

int main() {
    int studentCount;

    // 학생 수 입력
    cout << "학생 수를 입력하세요: ";
    cin >> studentCount;

    // 학생 구조체 동적 메모리 할당
    Student* students = new Student[studentCount];

    // 학생 정보 입력
    for (int i = 0; i < studentCount; i++) {
        cout << "학생 " << (i + 1) << "의 이름을 입력하세요: ";
        cin >> students[i].name;
        cout << "학생 " << (i + 1) << "의 중간 점수를 입력하세요: ";
        cin >> students[i].midterm;
        cout << "학생 " << (i + 1) << "의 기말 점수를 입력하세요: ";
        cin >> students[i].final;
    }

    // 이진 탐색 트리 생성
    TreeNode* root = nullptr;
    for (int i = 0; i < studentCount; i++) {
        root = insert(root, students[i]);
    }

    // 학생 정보 출력
    cout << "\n학생 정보 (이름 순서):\n";
    inorder(root);

    // 메모리 해제
    freeTree(root);
    delete[] students;

    return 0;
}


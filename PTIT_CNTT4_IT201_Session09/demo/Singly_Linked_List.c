//
// Created by Hikari on 02/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
// Định nghĩa cấu trúc Node (nút) trong danh sách liên kết đơn
typedef struct Node {
    int data;              // Dữ liệu của node (kiểu int)
    struct Node *next;     // Con trỏ trỏ đến node kế tiếp
} Node;

// Hàm tạo node mới với giá trị cho trước
Node *createNode(int value) {
    // Cấp phát bộ nhớ động cho một node mới
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Gán giá trị vào node
    newNode->data = value;

    // Con trỏ next của node mới trỏ đến NULL (chưa nối với node nào khác)
    newNode->next = NULL;

    // Trả về con trỏ trỏ đến node vừa tạo
    return newNode;
}

// Hàm in toàn bộ danh sách liên kết từ node đầu đến cuối
void printList(Node *head) {
    // Node *current = head;  // Duyệt danh sách bắt đầu từ node đầu (head) có thể sử dụng cách này thay head

    // Lặp qua từng node cho đến khi gặp NULL (kết thúc danh sách)
    // while (current != NULL) {
    //     printf("%d -> ", current->data);  // In ra giá trị của node hiện tại
    //     current = current->next;          // Di chuyển đến node tiếp theo
    // }
    while (head !=NULL) {
        printf("%d ",head->data);
        head = head -> next;
    }

    printf("NULL\n"); // Kết thúc danh sách
}

int main() {
    // Khởi tạo danh sách rỗng ban đầu
    Node *head = NULL;

    // Tạo các node với giá trị 1, 2, 3
    Node *node1 = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);

    // Gán node1 làm node đầu tiên của danh sách
    head = node1;

    // Nối node1 tới node2, và node2 tới node3
    node1->next = node2;
    node2->next = node3;

    // In toàn bộ danh sách ra màn hình
    printList(head);

    return 0;
}

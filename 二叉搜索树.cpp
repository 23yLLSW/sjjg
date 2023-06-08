#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} tree;

tree* create_node(int data) {
    tree* new_node = (tree*)malloc(sizeof(tree));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

tree* add(tree* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }

    if (data < root->data) {
        root->left = add(root->left, data);
    }
    else if (data > root->data) {
        root->right = add(root->right, data);
    }

    return root;
}

void print_tree(tree* root) {
    if (root == NULL) {
        return;
    }

    printf("%d\n", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

void search(tree* root, int data) {
    if (root == NULL) {
        printf("Not found\n");
        return;
    }

    if (root->data == data) {
        printf("Found\n");
        return;
    }

    if (data < root->data) {
        search(root->left, data);
    }
    else {
        search(root->right, data);
    }
}

int main() {
    tree* root = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        root = add(root, data);
    }

    printf("The tree is:\n");
    print_tree(root);

    printf("Enter the data to search: ");
    scanf("%d", &data);
    search(root, data);

    return 0;
}

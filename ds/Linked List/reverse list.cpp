// Only function

void reverse() {
    Node* current = new Node();
    Node* pre = new Node();
    Node* post = new Node();
    current = head;
    pre = NULL;
    post = current->next;
    while(current->next != NULL) {
        current->next = pre;
        pre = current;
        current = post;
        post = post->next;
    }
    current->next = pre;
    head = current;
}
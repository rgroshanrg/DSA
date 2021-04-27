void push_front(int ele) {
    Node* newele = new Node();
    newele->data = ele;
    newele->next = NULL;
    if(head == NULL) {
        head = newele;
    } else {
        newele->next = head;
        head = newele;
    }
}
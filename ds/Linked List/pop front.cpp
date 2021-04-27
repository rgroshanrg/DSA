void pop_front() {
    if(head == NULL) {
        cout << "\n List is Empty";
    } else {
        Node* temp = new Node();
        if(head->next == NULL) {
            temp = head;
            head = NULL;
            delete temp;
        } else {
            temp = head;
            head = temp->next;
            delete temp;
        }
    }
}
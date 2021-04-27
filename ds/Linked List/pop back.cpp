void pop_back() {
    if(head == NULL) {
        cout << "\n List is Empty";
    } else {
        Node* temp = new Node();
        for(temp = head; (temp->next)->next != NULL; temp = temp->next);
        delete temp->next;
        temp->next = NULL;
    }

}
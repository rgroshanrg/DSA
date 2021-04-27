void push_back(int ele) {
    Node* newele = new Node();
    newele->data = ele;
    newele->next = NULL;
    if(head == NULL) {
        head = newele;
    } else {
        Node* temp = new Node();
        for(temp = head; temp->next != NULL; temp = temp->next);
        temp->next = newele;
    }
}
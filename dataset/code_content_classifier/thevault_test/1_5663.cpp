void printBetween (struct node* temp, int n1, int n2) {
	if (temp == NULL) {
		return;
	}
	if (temp->data > n1) {
		printBetween(temp->left, n1, n2);
	}
	if (temp->data >= n1 && temp->data <= n2) {
		printf ("%d\t", temp->data);
	}
	if (temp->data < n2) {
		printBetween(temp->right, n1, n2);
	}
}
class Node
{
	public:
		int data;
		Node *next;

		Node(int element, Node *p = nullptr){
			data = element;
			next = p;
		}

		Node() {}
};

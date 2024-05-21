
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }

    // Insert a node at the start
    public Node addNodeAtStart(Node head, int newData) {
        Node newNode = new Node(newData);
        newNode.next = head;
        head = newNode;
        return head;

    }

    // Insert a node at the end
    public void addNodeAtEnd(Node head, int newData) {
        Node newNode = new Node(newData);

        if (head == null) {
            head = newNode;
            return;
        }

        Node last = head;
        while (last.next != null)
            last = last.next;

        last.next = newNode;

    }

    // Insert a node after a given node
    public void addNodeAfter(Node head, Node previousNode, int newData) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (previousNode == null) {
            System.out.println("Previous node cannot be null");
            return;
        }

        Node newNode = new Node(newData);
        newNode.next = previousNode.next;
        previousNode.next = newNode;
    }

    // add node before a given node
    public void addNodeBefore(Node head, Node nextNode, int newData) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (nextNode == null) {
            System.out.println("Next node cannot be null");
            return;
        }

        Node newNode = new Node(newData);

        if (head == nextNode) {
            head = newNode;
            head.next = nextNode;
            return;
        }

        Node temp = head;
        while (temp.next != nextNode) {
            temp = temp.next;
        }
        newNode.next = nextNode;

        temp.next = newNode;
    }

    // Print the list
    public void printList(Node head) {
        while (head != null) {
            System.out.print(" -> " + head.data);
            head = head.next;
        }
    }

    // Search for a node
    public Node searchNode(Node head, int key) {
        if (head == null) {
            System.out.println("List is empty");
            return null;
        }
        while (head != null) {
            if (head.data == key) {
                return head;
            }
            head = head.next;
        }
        return null;
    }

    // Delete node from start
    public Node deleteNodeFromStart(Node head) {
        if (head == null) {
            System.out.println("List is empty");
            return null;
        }
        head = head.next;
        return head;
    }

    // Delete node from end
    public void deleteNodeFromtEnd(Node head) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }

        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }
}

class Main {
    public static void main(String[] args) {
        Node head = new Node(10);
        head = head.addNodeAtStart(head, 43);
        head = head.addNodeAtStart(head, 63);
        head = head.addNodeAtStart(head, 34);

        // head.addNodeAtEnd(head, 42);

        // Node previousNode = head;
        // head.addNodeAfter(head, previousNode, 100);

        Node nextNode = head;
        head.addNodeBefore(head, nextNode, 200);

        Node searchNode = head.searchNode(head, 432);
        if (searchNode != null) {
            System.out.println("Node found " + searchNode.data);
        } else {
            System.out.println("Node not found");
        }

        head = head.deleteNodeFromStart(head);
        head = head.deleteNodeFromStart(head);

        head.deleteNodeFromtEnd(head);

        head.printList(head);
    }
}
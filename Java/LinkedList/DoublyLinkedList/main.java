package Java.LinkedList.DoublyLinkedList;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }

    // Insert node at start
    public Node addNodeAtStart(Node head, int newData) {
        if (head == null) {
            Node newNode = new Node(newData);
            head = newNode;
            return head;
        }

        Node newNode = new Node(newData);
        newNode.next = head;
        head.prev = newNode;
        head = newNode;
        return head;

    }

    // Insert node at end
    public Node addNodeAtEnd(Node head, int newData) {
        if (head == null) {
            Node newNode = new Node(newData);
            head = newNode;
            return head;
        }

        Node newNode = new Node(newData);

        Node last = head;
        while (last.next != null)
            last = last.next;

        last.next = newNode;

        newNode.prev = last;

        return head;
    }

    // Insert node at specific position
    public Node addNodeAtPosition(Node head, int position, int newData) {
        if (head == null) {
            System.out.println("List is empty");
            return head;
        }
        if (position < 0) {
            System.out.println("Position cannot be negative");
            return head;
        }
        Node newNode = new Node(newData);
        if (position == 0) {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
            return head;
        }

        Node current = head;

        int count = 0;
        while (count < position - 1 && current != null) {
            current = current.next;
            count++;
        }
        if (current == null) {
            System.out.println("Position is greater than the length of the list");
            return head;
        }

        newNode.next = current.next;
        current.next = newNode;
        current.next.prev = newNode;
        newNode.prev = current;

        return head;
    }

    // Delete node at start
    public Node deleteNodeAtStart(Node head) {
        if (head == null) {
            System.out.println("List is empty");
            return head;
        }
        if (head.next == null) {
            head = null;
            return head;
        }

        head = head.next;
        head.prev = null;
        return head;

    }

    // Delete node at end
    public Node deleNodeAtEnd(Node head) {
        if (head == null) {
            System.out.println("List is empty");
            return head;
        }
        if (head.next == null) {
            head = null;
            return head;
        }

        Node last = head;
        while (last.next != null) {
            last = last.next;
        }

        last.prev.next = null;
        return head;
    }

    // Delete node at specific position
    public Node deleteNodeAtPosition(Node head, int position) {
        if (head == null) {
            System.out.println("List is empty");
            return head;
        }
        if (position < 0) {
            System.out.println("Position cannot be negative");
            return head;
        }
        if (position == 0 && head.next == null) {
            head = null;
            return head;
        }
        if (position == 0) {
            head = head.next;
            head.prev = null;
            return head;
        }

        Node current = head;
        int count = 0;
        while (count < position - 1 && current != null) {
            current = current.next;
            count++;
        }

        if (current == null) {
            System.out.println("Position is greater than the length of the list");
            return head;
        }

        if (current.next == null) {
            current.prev.next = null;
            return head;
        }

        current.next = current.next.next;
        if (current.next != null)
            current.next.prev = current;

        return head;
    }

    // Print the list from start
    public void printFromStart(Node head) {
        while (head != null) {
            System.out.print(" => " + head.data);
            head = head.next;
        }
        System.err.println();
    }
}

public class main {
    public static void main(String[] args) {

        Node node = new Node(10);
        node = node.addNodeAtEnd(node, 20);
        node = node.addNodeAtEnd(node, 30);
        node = node.addNodeAtEnd(node, 40);

        // node = node.addNodeAtEnd(node, 50);
        // node = node.addNodeAtEnd(node, 60);

        node.printFromStart(node);

        // node = node.addNodeAtPosition(node, 1, 10);
        node.printFromStart(node);
        // node = node.deleteNodeAtStart(node);
        node.printFromStart(node);

        // node.deleNodeAtEnd(node);
        node.printFromStart(node);

        node = node.deleteNodeAtPosition(node, 3);
        node.printFromStart(node);

    }
}

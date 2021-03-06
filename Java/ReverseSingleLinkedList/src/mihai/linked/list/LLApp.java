package mihai.linked.list;

import mihai.linked.list.utils.LinkedListsUtils;
import java.util.Date;

public class LLApp {

    public static void main(String[] args) {

        LinkedList<Integer> list = new LinkedList<>();
        list.append(new Integer(24));
        list.append(new Integer(23));
        list.printList();
        list.deleteWithValue(23);
        list.deleteWithValue(24);
        list.printList();

        System.out.println("Printed initial list: ");
        list.append(2);
        list.append(23);
        list.append(25);
        list.prepend(14);
        list.printList();

        System.out.println("Printed reversed list:");
        list.reverse();
        list.printList();

        System.out.println("Deleted node with value = 23");
        list.deleteWithValue(23);
        System.out.println("The resulted list: ");
        list.printList();

        System.out.println("Insert 1 at position 0:");
        list.insertAtPosition(1,0);
        list.printList();
        System.out.println("Insert 2 at position 3:");
        list.insertAtPosition(2,3);
        list.printList();

        System.out.println("The size the list is: " + list.size());

        System.out.println("Delete item at position 4");
        list.deleteAtPosition(4);
        list.printList();

        LinkedList a = new LinkedList();
        LinkedList b = new LinkedList();
        System.out.println(LinkedListsUtils.CompareLists(a.getHead(),b.getHead()));
        a.prepend(1);
        b.prepend(1);
        System.out.println(LinkedListsUtils.CompareLists(a.getHead(),b.getHead()));

        a.append(2);a.append(3);
        b.append(4);b.append(5);
        LinkedList c = LinkedListsUtils.MergeLists(a,b);
        c.printList();

        System.out.println(c.elementAtPosition(6));
        LinkedListsUtils.RemoveDuplicates(c);
        c.printList();
    }
}

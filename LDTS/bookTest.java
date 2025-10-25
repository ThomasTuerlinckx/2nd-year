public class bookTest {
    public static void main(String[] args) {
        Book book1 = new Book("Java Basics", "John Doe", 300);
        
        book1.DisplayInfo();
        
        // Test setters
        book1.setTitle("Advanced Java");
        book1.setPages(400);
        book1.DisplayInfo();
        
        // Test getters
        System.out.println("Author: " + book1.getAuthor());
        System.out.println("Title: " + book1.getTitle());
        System.out.println("Pages: " + book1.getPages());
    }
}

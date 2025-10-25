public class Book{
  private String title;
  private String author;
  private int pages;



  //constructor
  public Book(String title, String author, int pages){
    this.title = title;
    this.author = author;
    this.pages = pages;
  }

  //gettter
  public String getAuthor(){
    return author;
  }
  public String getTitle(){
    return title;
  }
  public int getPages(){
    return pages;
  }


  //setter 

  public void setTitle(String newTitle){
    title = newTitle;
  }
  public void setAuthor(String newAuthor){
    author = newAuthor;
  }
  public void setPages(int newPages){
    pages = newPages;
  }

  public void DisplayInfo(){
    System.out.println("title " + title+ "author " + author +"pages " + pages);
  }

  
  

}

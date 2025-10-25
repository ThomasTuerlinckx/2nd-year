public class manga extends Book{
  private int kanjis;

  public manga(String title, String author, int pages, int kanjis){
    super(title, author, pages);
    this.kanjis=kanjis;
  }

  public void kanjisSize(){
    System.out.println(kanjis + "can be found");
  }

  @Override
  public void DisplayInfo(){
    super.DisplayInfo();
    System.out.println("we can find" + kanjis + "in this manga");
  }




}


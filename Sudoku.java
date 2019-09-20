import java.io.*;
import java.util.*;
public class Sudoku {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fos=new FileInputStream("simple");
		int i;
		//BufferedOutputStream bos=new BufferedOutputStream(fos);
		while((i=fos.read())!=-1)
		{
			System.out.print(i);
		}
		
	}

}

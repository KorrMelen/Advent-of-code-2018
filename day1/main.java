import java.io.*;
import java.util.*;

/*deuxiéme parti*/

public class main {


	public static void main(String[] args){
		int freqency = 0;
		/*List reaches = new ArrayList();
		reaches.add (freqency);
		boolean reaches_first = false;
		int val_reaches = 0;*/
		/*while (!reaches_first){*/
			try{
				File f = new File ("input_jour1.txt");
	    		FileReader fr = new FileReader (f);
	    		BufferedReader br = new BufferedReader (fr);

	    		try{
	    			String line = br.readLine();
	        		while (line != null /*&& !reaches_first*/){
	        			int freq = 0;
	        			if(line.charAt(0)=='-'){
			        		for (int i = 1; i < line.length(); ++i){
			        			freq += (line.charAt(i) - '0') * Math.pow(10,(line.length()-i-1));
			        		}
			        		//System.out.println(freq);
			        		freqency -= freq;
			        	}else{
			        		for (int i = 1; i < line.length(); ++i){
			        			freq += (line.charAt(i) - '0') * Math.pow(10,(line.length()-i-1));
			        		}
			        		//System.out.println(freq);
			        		freqency += freq;
			        	}
			        	/*if(reaches.contains(freqency)){
			        		reaches_first = true;
			        		val_reaches = freqency;
			        	} 
			        	else reaches.add(freqency);*/
			        	line = br.readLine();
	        		}
			        br.close();
			        fr.close();
			    }
			    catch (IOException exception){
			        System.out.println ("Erreur lors de la lecture : " + exception.getMessage());
			    }
			}
			catch (FileNotFoundException exception){
			    System.out.println ("Le fichier n'a pas été trouvé");
			}
		/*}
		System.out.println(val_reaches);*/
		System.out.println(freqency);
	}
}
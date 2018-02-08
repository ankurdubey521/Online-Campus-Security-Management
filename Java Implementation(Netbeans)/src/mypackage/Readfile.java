/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypackage;
import java.io.*;
import java.util.*;
import javax.swing.JOptionPane;
import java.lang.*;

/**
 *
 * @author vinay
 */
public class Readfile {
    private Scanner x;
    private Scanner y;
    public String k;
    public String r;
    public String sst;
    public String ar[] = new String[4];
  // public String list[] = new String[100];
    public ArrayList<String>al = new ArrayList();
    public String fn;
    public String ln;
    public String ag;
    public String ps;
    
    public int openfile(String setid){
        try{k=setid;
        k = k.concat(".txt");
            x=new Scanner(new File(k));
            return 0;
        }
        catch(Exception e){
           JOptionPane.showMessageDialog(null,"You are not Registered","login error",JOptionPane.ERROR_MESSAGE);
           return 1;
        }
    }
    public int kfile(String set){
        try{r=set;
        r = r.concat(".txt");
            x=new Scanner(new File(r));
            return 0;
        }
        catch(Exception e){
           //JOptionPane.showMessageDialog(null,"You are not Registered","login error",JOptionPane.ERROR_MESSAGE);
           return 1;
        }
    }
   
    public void readfile(){
        while(x.hasNext()){           
            fn=x.next();
            ln=x.next();
             ag=x.next();
             ps=x.next();
        }
       /* String nl[] = new String[1];
        nl[0]="";
        return nl;*/
       
    }
    
  public void rfile(){
       // int i=0;
         while(x.hasNext()){ 
             String z=x.next();              
             al.add(z);
         } 
         
      // add elements to the array list
      
    }
  public void rmyfile(){
       while(x.hasNext()){  
           sst=x.next();
          
       }
    }
    public ArrayList<String> rgive(){
        return al;
    }
    public String rmygive(){
        return sst;
    }
        public String[] give(){
        ar[0]= fn;
        ar[1]= ln;
        ar[2]=ag; 
        ar[3]=ps; 
        return ar;
            
        }
        
      /* public String[] givelist(){
           return list;
       }*/
    
    public void closefile(){
        x.close();}
     
    public void yclosefile(){
        y.close();}

}

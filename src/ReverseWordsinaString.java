public class Solution {
    public String reverseWords(String s) {
    	String st = s.trim();
        String sm[] = st.split(" ");
        int len = sm.length;
        for(int i=0;i<len/2;i++){
            String tmp = sm[i];
            sm[i] = sm[len-i-1];
            sm[len-i-1] = tmp;
        }
        String hello = "";
        for(int j=0;j<len;j++){
        		sm[j] = sm[j].trim();
        	if(j!=len-1 && !sm[j].trim().isEmpty())
                hello += sm[j]+" ";
            else
                hello += sm[j];


        }
        return hello.trim();
    }
}

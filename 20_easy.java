/*******************************************************************
1.遍历字符串（String类型）
  char[]  c = str.toCharArray();
  for(int i=0;i < c.length;i++) {
	  System.out.println(c[i]);
  }
  //查看String类型字符串s长度
  s.length()
  //查看字符串数组c长度
  c.length
 2.stack
  Stack<Character> st=new Stack<>();
  //判栈空
  st.empty()
  //查看栈顶值
  st.peek()
  //入栈
  st.push(x)
  //出栈
  st.pop()
*******************************************************************/
class Solution {
    public boolean isValid(String s) {
        if(s.length()==0)
            return true;
        Stack<Character> st=new Stack<>();
        for(char c:s.toCharArray())
        {
            if(c=='('||c=='['||c=='{')
            {
                st.push(c);
                continue;
            } 
            else if(st.empty()||c==')'&&st.peek()!='('||c==']'&&st.peek()!='['||c=='}'&&st.peek()!='{')
                return false;
            else
                st.pop();
        }
        if(!st.empty())
            return false;
        return true;
    }
}

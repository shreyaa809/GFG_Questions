class Solution {
  public:
    int priority(char ch)
    {
        if (ch=='^')
        return 3;
        else if (ch=='*'||ch=='/')
        return 2;
        else if (ch=='+'||ch=='-')
        return 1;
        return -1;
    }
    string infixToPostfix(string& s) 
    {
        // code here
        stack<char>st;
        string ans="";
        
        for (int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if (isalpha(ch)||isdigit(ch))
            ans+=ch;
            else if (ch=='(')
            st.push(ch);
            else if (ch==')')
            {
                while (!st.empty()&&st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop(); //pop out '('
            }
            else
            {
                if (!st.empty()&& priority(ch)>priority(st.top()))
                st.push(ch);
                else
                {
                    while (!st.empty()&&(
                     priority(ch) < priority(st.top()) ||
                       (priority(ch) == priority(st.top()) && ch != '^')))
                    {
                    ans+=st.top();
                    st.pop();
                    }
                    st.push(ch);
                }
            }
        }
        while (!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

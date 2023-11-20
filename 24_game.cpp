class Solution {
public:
    vector<double>getvalidops(double a,double b)
    {
        vector<double>validops;
        validops.push_back(a+b);
        validops.push_back(a*b);
        validops.push_back(a-b);
        validops.push_back(b-a);
        if(abs(a)>FLT_EPSILON)
        {
            validops.push_back(a/b);
        }
        if(abs(b)>FLT_EPSILON)
        {
            validops.push_back(b/a);
        }
        return validops;
    }
    bool solve(vector<double>&cards)
    {
        int n=cards.size();
        if(n==1)
        {
            return abs(24.0-cards[0])<=FLT_EPSILON;
        }
        
        for(int f=0;f<n;f++)
        {
            for(int s=0;s<n;s++)
            {
                if(f==s)continue;
                double fno=cards[f];
                double sno=cards[s];
                vector<double>next;
                vector<double>validops=getvalidops(fno,sno);
                for(auto &validop:validops)
                {
                    next.clear();
                    next.push_back(validop);
                    for(int i=0;i<n;i++)
                    { 
                       if(i==f || i==s)continue;
                       next.push_back(cards[i]);
                    }
                    if(solve(next))
                    {
                       return true;
                    }
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>newcards(cards.begin(),cards.end());
        return solve(newcards);
    }
};

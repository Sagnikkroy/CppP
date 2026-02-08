//seconnd smallest
smallest=INT_MAX;
second_smallest=INT_MAX;
largest=INT_MIN;
second_largest=INT_MIN;

secondsmallest(vector<int> &v, int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]<smallest)
        {
            second_smallest=smallest;
            smallest=v[i];
        }
    }
}
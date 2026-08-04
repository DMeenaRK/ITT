int buyChoco(int* prices, int pricesSize, int money){
    for(int i=0;i<pricesSize;i++)
    {
        for(int j=i+1;j<pricesSize;j++)
        {
            if(prices[i]>prices[j])
            {
                int temp = prices[i];
                prices[i] = prices[j];
                prices[j] = temp;
            }
        }
    }
    int sum = prices[0]+prices[1];
    int total = money - sum;
    if(total >= 0)
    {
        return total;
    }
    else
    {
        return money;
    }
}
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace Codejam
{
class SantaDaDhaba
{
int MaxDays(string[] prices, int budget)
{
int[] minarr = new int[prices[0].Length];
int total = 0; int x;

int cnt = 0;
for (int i = 0; i < prices.Length; i++)
{
Array.Clear(minarr, 0, prices[0].Length);
int min = 0;

int min2=0;
if(i>=7)
{
min = 0;

for (x = 0; x < prices[0].Length; x++)
{
int sum = 0;

for (int p = i - 7; p >= 0; p = p - 7)
{

sum = sum + value(prices[p][x]);
}
minarr[x] = sum;


}
min = minarr.Min();
}

for (x = 0; x < prices[0].Length; x++)
{
minarr[x] += value(prices[i][x]);

}
min2=minarr.Min();
total += min2 - min;
if (total <= budget)
{
cnt++;



}
else break;


}

return cnt;
}


public int value(char x)
{
if (char.IsDigit(x))
{
return x - 48;
}
else if (char.IsUpper(x))
{
return x - 55;
}
else if (char.IsLower(x))
{
return x - 61;
}
else
return 0;
}

#region Testing code Do not change
public static void Main(String[] args)
{
String input = Console.ReadLine();
SantaDaDhaba dhaba = new SantaDaDhaba();

do
{
var inputParts = input.Split('|');
string[] prices = inputParts[0].Split(',');
Console.WriteLine(dhaba.MaxDays(prices, Int32.Parse(inputParts[1])));
input = Console.ReadLine();
} while (input != "-1");
}
#endregion
}
}

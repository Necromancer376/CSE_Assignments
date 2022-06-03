#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	double maxW;
	cout << "Size: ";
	cin >> n;
	cout << "Max Weight: ";
	cin >> maxW;

	vector<double> bag(n);
	cout << "Items: ";
	for(int i=0; i<n; i++)
		cin >> bag[i];

	sort(bag.rbegin(), bag.rend());

	for(int i=0; i<bag.size(); i++)
	{
		if(maxW - bag[i] >= 0)
		{
			maxW -= bag[i];
			bag.erase(bag.begin() + i);
			i--;
		}
		else
		{
			bag[i] -= maxW;
			maxW = 0;
			break;
		}
	}

	cout << "Items to discard: " << endl;
	if(bag.empty())
		cout << "None" << endl;
	else
	{
		for(int i=0; i<bag.size(); i++)
		{
			cout << bag[i] << endl;
		}
	}

	return 0;
}



// struct Item
// {
// 	int weight, price;
// };

// struct Answer
// {
// 	int weight;
// 	double price;
// };

// bool compare(struct Item i1, struct Item i2)
// {
// 	double r1 = (double)i1.price / (double)i1.weight;
//     double r2 = (double)i2.price / (double)i2.weight;
//     return r1 > r2;
// }


// struct Answer Soln(int maxW, struct Item arr[], int n)
// {
// 	sort(arr, arr+n, compare);

// 	int w = 0;
// 	double ans = 0.0;

// 	for(int i=0; i<n; i++)
// 	{
// 		if(w + arr[i].weight <= maxW)
// 		{
// 			w += arr[i].weight;
// 			ans += arr[i].price;
// 		}
// 		else
// 		{
// 			int change = maxW - w;
// 			ans += (arr[i].price * (double)change / (double)arr[i].weight);
// 			w += change;
// 			break;
// 		}
// 	}

// 	struct Answer soln;
// 	soln.weight = w;
// 	soln.price = ans;
// 	return soln;
// }


// int main()
// {
// 	int n, W;
// 	cout << "Max Weight: ";
// 	cin >> W;
// 	cout << "Size: ";
// 	cin >> n;
// 	struct Item arr[n];
// 	struct Answer ans;

// 	cout << "Items [Weight, price]" << endl;
// 	for(int i=0; i<n; i++)
// 	{
// 		cin >> arr[i].weight >> arr[i].price;
// 	}

// 	ans = Soln(W, arr, n);

// 	cout << "Max weight to value: " << ans.price << endl;
// 	cout << "Max weight to weight: " << ans.weight << endl;

// 	return 0;
// }

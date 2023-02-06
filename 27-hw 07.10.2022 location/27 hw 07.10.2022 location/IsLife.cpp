#include "IsLife.h"
#include "IsLife.h"
#include <iostream>
using namespace std;


IsLife::IsLife(Fox& fox, Bunny& bunny, Grass& gras)
{
	
	if (fox.GetHabitat() == bunny.GetHabitat())
	{
		fox.Remainder(5);

		if (fox.GetCount() >= bunny.GetCount())
		{
			bunny.Remainder(0);
			cout << endl << endl;
			bunny.Show(); 
			cout << endl << endl;
		}
		
		else
		{
			
			bunny.Remainder(bunny.GetCount() - fox.GetCount());
			
			if (gras.GetCount() <= 0)
			{
				bunny.Remainder(0);
			}
			else
			{
				
				if (gras.GetCount() > bunny.GetCount())
				{
					gras.SetCount(gras.GetCount() - bunny.GetCount());
				}
				else 
				{
					gras.SetCount(0);
				}
			}
		}
	}
	
	else
	{
		
		fox.Remainder(fox.GetCount() / 2);
	
		if (gras.GetCount() <= 0)
		{
			bunny.Remainder(0);
		}
		else
		{
			
			if (gras.GetCount() > bunny.GetCount())
			{
				
				gras.SetCount(gras.GetCount() - bunny.GetCount());
			}
			else 
			{
				gras.SetCount(0);
			}
		}
	}
	
	cout << "\t\tAFTER" << endl;
	fox.Show();
	cout << endl << endl;
	bunny.Show();
	cout << endl << endl;
	gras.Show();
	cout << endl << endl;
}

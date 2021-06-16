#include<iostream>
using namespace std;
class Player
{
	/*private:
		int id;
		static int next_id;*/
	public:
		static int id;
		int getID()
		{
			return id;
		}
		/*Player()
		{ 
			id = next_id++;
		}*/

};
int Player::id=1;

int main()
{
	Player p1;
	cout<<p1.getID()<<" ";
	//Player p2;
	//cout<<p2.getID()<<" ";
	return 0;
}
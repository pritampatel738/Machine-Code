#include<bits/stdc++.h>
using namespace std;

class Player{
	public:
		string name;
		int score;
		int isOpen;
		
		Player(string a,int b){
			name = a;
			score = b;
			isOpen = 0;
		}
		
};

int randn(){
	//srand(time());
    int x = ((rand() * rand() + 2*rand()) % 6 + 1);
    return x;
}

int main(){
	
	map<int,int> snakes;
	map<int,int> ladder;
	
	snakes[62] = 5;snakes[95] = 75;snakes[98] = 64;snakes[93] = 73;snakes[33] = 6;snakes[49] = 9;snakes[88] = 16;
	snakes[41] = 20;snakes[56] = 53;ladder[2] = 37;ladder[27] = 46;ladder[10] = 32;ladder[88] = 16;ladder[51] = 68;
	ladder[61] = 79;ladder[65] = 84;ladder[71] = 91;ladder[81] = 100;
	
	
	queue<Player> q;
	queue<string> winners;
	Player p1 = Player("Pritam",0);
	Player p2 = Player("Bawal",0);
	q.push(p1);
	q.push(p2);
	while(q.size() != 1){
		
		Player p = q.front();
		q.pop();
		
		int x = randn();
		if(p.isOpen == 0 && x != 6){
			q.push(p);
			continue;
		}
		if(p.isOpen == 0 && x==6){
			cout<<"Opening "<<p.name<<endl;
			p.isOpen = 1;
			q.push(p);
			continue;
		}
		if(p.isOpen == 0){
			q.push(p);
			continue;
		}
		p.score += x;
		cout<<x<<endl;
		if(p.score > 100){
			p.score -= x;
			cout<<"Overflow occured. Value > 100.\n";
			q.push(p);
			continue;
		}
		if(snakes.find(p.score) != snakes.end()){
			p.score = snakes[p.score];
			cout<<p.name<<" has found a snake.\n";
			
		}
		else if(ladder.find(p.score) != ladder.end()){
			cout<<p.name<<" has found a ladder from "<<p.score<<" \n";
			p.score = ladder[p.score];
		}
		if(p.score == 100){
			cout<<p.name<<" has won the game.\n";
			winners.push(p.name);
			continue;
		}
		cout<<p.name<<" has a score of "<<p.score<<endl;
		q.push(p);
		
		
	}
	
	cout<<"Winners order is : \n";
	while(!winners.empty()){
		cout<<winners.front()<<endl;
		winners.pop();
	}
	
	
	return 0;
}

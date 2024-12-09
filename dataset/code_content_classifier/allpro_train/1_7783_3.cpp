#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

const int MOD = 12345678;


class Cell
{
public:
  int v;
  Cell* parent;
  bool visited, candidate,leaf;
  vector<Cell*> child;

  Cell(int v, Cell* parent)
    :v(v),parent(parent),visited(false),candidate(false),leaf(false)
  {}

  void update() {
    int p = v;
	v = 3*v + 1;

    while(v%2!=1) {
      v/=2;
    }

    v %= MOD;
	if(p < v) candidate = true;
  }
};

int count(Cell* cell)
{
	int res = 1;
	for(int i=0; i<cell->child.size(); i++)
		res += count(cell->child[i]);

	return res;
}

void getValues(Cell* cell, vector<int>& res)
{
	res.push_back(cell->v);
	for(int i=0; i<cell->child.size(); i++) {
		getValues(cell->child[i], res);
	}
}

Cell* getNewLeader(Cell* cell, int v)
{
	if(cell->v == v) return cell;

	for(int i=0; i<cell->child.size(); i++){
		Cell* res = getNewLeader(cell->child[i], v);
		if(res != NULL) return res;
	}

	return NULL;
}

void checkLeaf(Cell* cell)
{
	if(cell->child.size() == 0) cell->leaf = true;
	for(int i=0; i<cell->child.size(); i++) {
		checkLeaf(cell->child[i]);
	}
}

Cell* selectLeader(Cell* root, bool& uniq)
{
	vector<int> values;
	getValues(root, values);

	sort(values.begin(), values.end(), greater<int>());

	if(values[0] == values[1]) {
		uniq = false;
		return root->child[0];
	}

	uniq = true;
	Cell* newleader = getNewLeader(root, values[0]);

	return newleader;
}

void add(Cell* parent, int v)
{
	parent->child.push_back(new Cell(v, parent));
}

void leaderBonus(Cell* leader)
{
  int v = (leader->v+1)/2;
  if(v%2==0) v -= 1;

  add(leader, v);
}

void leafBonus(Cell* cell)
{
	if(cell->leaf){
      int v = (cell->v+1)/2;
      if(v%2==0) v += 1;

      if(cell->candidate) {
		 add(cell, v);
	  }
    }
	else{
      for(int i=0; i<cell->child.size(); i++)
		leafBonus(cell->child[i]);
    }
}

void newTree(Cell* prev, Cell* next)
{
  prev->visited = true;
  Cell* c = new Cell(prev->v, next);
  next->child.push_back(c);

  if(prev->parent) {
    if(!prev->parent->visited) {
      if(prev->parent->v != -1) {
		prev->parent->visited = true;
		newTree(prev->parent, c);
      }
    }
  
    for(int i=0; i<prev->child.size(); i++) {
      if(!prev->child[i]->visited) {
		prev->child[i]->visited = true;
		newTree(prev->child[i], c);
      }
    }
  }
}

void remove(Cell *cell)
{
	for(int i=0; i<cell->child.size(); i++) {
		remove(cell->child[i]);
	}

	delete cell;
}

bool died(Cell *cell, bool leader)
{
	if(cell->v == 1) {
		if(leader) {
			remove(cell);
		}
		else {
			Cell* parent = cell->parent;
			int n=-1;
			for(int i=0; i<parent->child.size(); i++) {
				if(parent->child[i] == cell) 
					n = i;
			}

			parent->child.erase(parent->child.begin()+n);
			
			if(cell->child.size() != 1)
			{
				remove(cell);
			}
			else {
				Cell* grandchild = cell->child[0];

				parent->child.push_back(grandchild);
				grandchild->parent = parent;
		
				delete cell;
				cell = NULL;
			}

			died(parent, false);
			return true;
		}
	}
	else {
		for(int i=0; i<cell->child.size(); i++) 
			if(died(cell->child[i], false)) break;
	}
	

  return false;
}

void update(Cell* cell)
{
	cell->update();
	for(int i = 0; i < cell->child.size(); i++) {
		update(cell->child[i]);
	}
}

void solve(int v)
{
  Cell* root = new Cell(-1, NULL);
  root->visited = true;
  add(root, v);

  Cell* leader = root->child[0];
  
  int cycle = 0, m = 1;
  while(1) {
    cycle++;

    update(leader);
	checkLeaf(leader);

	died(root, true);
	if(root->child.size() == 0) break;

	leafBonus(leader);

    Cell* newroot = new Cell(-1, NULL);
	newroot->visited = true;

	bool uniq;
    leader = selectLeader(root, uniq);
    newTree(leader, newroot);

	leader = newroot->child[0]; 

    if(uniq) leaderBonus(leader);

    m = max(m, count(leader));

    remove(root->child[0]);

    root = newroot;
  }

  cout << cycle << " " << m << endl;
}

int main()
{
  int N;
  while(cin >> N, N)
  {
      solve(N);
  }
}
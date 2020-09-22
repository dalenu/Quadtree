#include "Quadtree.h"

Quadtree::Quadtree(std::string city, double x, double y, int population, int cost, int salary) {
	name = city;
	lng = x;
	lat = y;
	
	attr = new int[3];
	attr[0] = population;
	attr[1] = cost;
	attr[2] = salary;

	branch = new Quadtree*[4];
	for(int i = 0; i < 4; i++) {
		branch[i] = nullptr;
	}

	size = 1;
}

Quadtree::~Quadtree() {
	clear();
}

int getdir(double x, double y, double x1, double y1) {
	int hor = (x > x1);
	int ver = (y > y1);
	
	if(x == x1) {
		if(y == y1) {
			return -1;
		}
		return (2 * ver);
	}

	if(y == y1) {
		return (3 - 2 * hor);
	}
	return (ver * (1 - hor) + (1 - ver) * hor + 2 * ver);
}

int Quadtree::insert(std::string city, double x, double y, int population, int cost, int salary) {	
	int dir = getdir(lng, lat, x, y);
	
	if (dir == -1) {
		return -1;
	}

	if (branch[dir] == nullptr) {
		size++;
		branch[dir] = new Quadtree(city, x, y, population, cost, salary);
		return 0;
	}

	int returnval = branch[dir]->insert(city, x, y, population, cost, salary);

	if (returnval == 0) {
		size++;
	}

	return returnval;
}


Quadtree* Quadtree::search(double x, double y) {
	int dir = getdir(lng, lat, x, y);
	if (dir == -1) {
		return this;
	}

	if (branch[dir] == nullptr) {
		return nullptr;
	}

	return branch[dir]->search(x, y);
}

int Quadtree::qmaster(double x, double y, int dir, int val, int mode) {
	Quadtree* head = search(x, y);
	if (head == nullptr) {
		return -1;
	}

	if (head->branch[dir] == nullptr) {
		return -1;
	}

	if (mode == 0) {
		return head->branch[dir]->qmax(val);
	}

	if (mode == 1) {
		return head->branch[dir]->qmin(val);
	}

	if (mode == 2) {
		return head->branch[dir]->qtot(val);
	}
}

int Quadtree::qmax(int val) {
	int max = attr[val];
	for (int i = 0; i < 4; i++) {
		if (branch[i] != nullptr) {
			max = std::max(branch[i]->qmax(val), max);
		}
	}
	return max;		
}

int Quadtree::qmin(int val) {
	int min = attr[val];
        for (int i = 0; i < 4; i++) {
                if (branch[i] != nullptr) {
                        min = std::min(branch[i]->qmin(val), min);
                }
        }
        return min;
}

int Quadtree::qtot(int val) {
	int total = attr[val];
	for(int i = 0; i < 4; i++) {
		if (branch[i] != nullptr) {
			total += branch[i]->qtot(val);
		}
	}
	return total;
}

void Quadtree::print() {
	if (branch[0] != nullptr) {
		branch[0]->print();
	}

	if (branch[1] != nullptr) {
		branch[1]->print();
	}

	std::cout << name << " ";

	if (branch[2] != nullptr) {
		branch[2]->print();
	}

	if (branch[3] != nullptr) {
		branch[3]->print();
	}
}

void Quadtree::clear() {
	for (int i = 0; i < 4; i++) {
		if (branch[i] != nullptr) {
			branch[i]->clear();
		}
	}
	delete branch;
	delete attr;
	free(this);
}

int Quadtree::getsize() {
	return size;
}

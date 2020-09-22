class Quadtree {
public:
	std::string name;
	double lng;
	double lat;
	int* attr;
	Quadtree** branch;
	int size;

	Quadtree(std::string city, double x, double y, int population, int cost, int salary);
	~Quadtree();
	int insert(std::string city, double x, double y, int population, int cost, int salary);
	Quadtree* search(double x, double y);
	int qmaster(double x, double y, int dir, int attr, int mode);
	int qmax(int val);
	int qmin(int val);
	int qtot(int val);
	void print();
	void clear();
	int getsize();
};

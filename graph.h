class graph{
	private:
	char label_ls[20][20];
	int adj_mat[20][20] = {0};
	int capacity = 0;
	int sptset[20];
	public:
	graph();
	void min_distance(int idx);
	void print();
	void add_vertex(char * label);
	void remove_vertex(char * label);
	void add_edge(char * label_one,char * label_two);
	void remove_edge(char * label_one,char*label_two);
	void dijkstra(char *label_one,char * label_two);
};

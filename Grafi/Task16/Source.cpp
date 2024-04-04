#include<iostream>



class CGraph {
public:
	CGraph();
	CGraph(int vertexes);
	~CGraph();
	void ReadIs(int v, std::istream& stream);
	void task16(int ac, int bc);

private:
	void init();
	void initis();
	void disopseis();

	int _vertexes;
	int* _isled;
};

int main(int argc, char* argv[])
{
	int v = 0;
	int ac = 0;
	int bc = 0;

	std::cin >> v;
	std::cin >> ac >> bc;

	CGraph g(v);
	g.ReadIs(v, std::cin);
	g.task16(ac, bc);

	return EXIT_SUCCESS;
}


CGraph::CGraph()
	: _vertexes(0), _isled(nullptr) {}

CGraph::CGraph(int vertexes)
	: _vertexes(vertexes), _isled(nullptr)
{
	initis();
}

CGraph::~CGraph()
{
	disopseis();
}




void CGraph::ReadIs(int v, std::istream& stream)
{
	_vertexes = v;
	initis();
	for (int j = 1; j < _vertexes; ++j)
	{
		stream >> _isled[j];
	}

}

void CGraph::task16(int ac, int bc)
{
	int a = ac;
	int b = bc;

	int suma = 1;
	int sumb = 1;

	while (a != 1 || b != 1)
	{
		if (a != 1)
		{
			a = _isled[a - 1];
			suma++;
		}

		if (b != 1)
		{
			b = _isled[b - 1];
			sumb++;
		}
	}

	if (sumb > suma)
	{
		a = bc;
		b = ac;
		ac = a;
		bc = b;
	}

	a = ac;
	b = bc;

	while (a != b)
	{
		while (a != 1 && a != b)
		{
			a = _isled[a - 1];
		}
		if (a == 1)
		{
			a = ac;
		}
		if (b == 1)
		{
			a = 1;
		}
		if (a == b)
		{
			break;
		}
		b = _isled[b - 1];
	}

	disopseis();

	std::cout << a;
}

void CGraph::initis()
{
	if (_vertexes == 0)
	{
		return;
	}
	_isled = new int [_vertexes] {0};
}

void CGraph::disopseis()
{
	delete[] _isled;
	_isled = nullptr;
}



﻿#include<iostream>

struct SEdge {
	int a;
	int b;
	int w;
	SEdge(int a = 0, int b = 0, int w = 1) : a(a), b(b), w(w) {}
	SEdge(const SEdge& src) : a(src.a), b(src.b), w(src.w) {}
	~SEdge() {}
	void set(int a, int b, int w)
	{
		this->a = a;
		this->b = b;
		this->w = w;
	}
	friend std::ostream& operator<<(std::ostream& stream, const SEdge& edge);
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	///выводит матрицу смежности графа
	void PrintMatrix();
	///выводит дуги графа
	void PrintEdges();
	///считывает матрицу смежности графа
	void ReadMatrix(int vertexes, std::istream& stream);
	///считывает дуги графа
	void ReadEdges(int edges, std::istream& stream, bool haveweight = false);
	int edgesCount();
	int roadsCount();
	int vertexCount();
	int power(int vertex);
	bool isTour();
	void Readev(std::istream& stream);
	void task5();

private:
	///создает матрицу смежности n*n и матрицу с дугами размера m
	void init();
	///создает матрицу смежности _vertexes*_vertexes
	void initMatrix();
	///создает матрицу матрицу с дугами размера _edges
	void initEdges();
	void initMatrixFromEdges();
	void initEdgesFromMatrix();
	int getVertexesCountFromEdges();
	int getEdgesCountFromMatrix();
	///удаляет матрицу смежности и матрицу с дугами
	void dispose();
	///удаляет матрицу смежности
	void disposeMatrix();
	///удаляет матрицу с дугами
	void disposeEdges();
	void disposeev();

	int _vertexes;
	int _edges;
	int** _matrix;
	int* _evmat;
	SEdge* _edge;
};

int main(int argc, char* argv[])
{
	CGraph g(3, 0);
	g.Readev(std::cin);
	g.task5();
	return EXIT_SUCCESS;
}


CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _edge(nullptr), _evmat(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _evmat(nullptr), _edge(nullptr)
{
	init();
}

CGraph::~CGraph()
{
	dispose();
}

void CGraph::PrintMatrix()
{
	if (_matrix == nullptr)
	{
		if (_edge == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initMatrixFromEdges();
	}
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 1; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	if (_edge == nullptr)
	{
		if (_matrix == nullptr)
		{
			std::cout << "Graph empty" << std::endl;
			return;
		}
		initEdgesFromMatrix();
	}
	for (int i = 0; i < _edges; ++i)
	{
		std::cout << _edge[i] << std::endl;
	}
}

void CGraph::ReadMatrix(int vertexes, std::istream& stream)
{
	_vertexes = vertexes;
	initMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			stream >> _matrix[i][j];
		}
	}
	initEdgesFromMatrix();
}

void CGraph::ReadEdges(int edges, std::istream& stream, bool haveweight)
{
	_edges = edges;
	initEdges();
	for (int i = 0; i < _edges; ++i)
	{
		stream >> _edge[i].a >> _edge[i].b;
		if (haveweight)
		{
			stream >> _edge[i].w;
		}
	}
	initMatrixFromEdges();
}

int CGraph::edgesCount()
{
	if (_edge == nullptr)
	{
		initEdgesFromMatrix();
	}
	return _edges;
}

int CGraph::roadsCount()
{
	return edgesCount() / 2;
}

int CGraph::vertexCount()
{
	if (_matrix == nullptr)
	{
		initMatrixFromEdges();
	}
	return _vertexes;
}

int CGraph::power(int vertex)
{
	int r = 0;
	for (int i = 0; i < vertexCount(); ++i)
	{
		r += (_matrix[vertex][i] != 0);
	}
	return r;
}

bool CGraph::isTour()
{
	for (int i = 0; i < vertexCount(); ++i)
	{
		int c = 0;
		for (int j = 0; j < vertexCount(); ++j)
		{
			if (_matrix[i][j] + _matrix[j][i] == 2)
			{
				return false;
			}
			/*
			0 1 0 0
			0 0 1 1
			1 0 0 0
			1 0 1 0
			*/
			/*
			5 | 3  = 7      0b101 | 0b011 = 0b111
			5 || 3 = true    true |  true = true

			*/
			c += (_matrix[i][j] | _matrix[j][i]);
		}
		if (c != vertexCount() - 1)
		{
			return false;
		}
	}
	return true;
}

void CGraph::init()
{
	dispose();
	initMatrix();
	initEdges();
}

void CGraph::initMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::initEdges()
{
	if (_edges == 0)
	{
		return;
	}
	_edge = new SEdge[_edges];
}

void CGraph::initMatrixFromEdges()
{
	disposeMatrix();
	_vertexes = getVertexesCountFromEdges();
	initMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		_matrix[_edge[i].a][_edge[i].b] = _edge[i].w;
	}
}

int CGraph::getEdgesCountFromMatrix()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			count += (_matrix[i][j] != 0);
		}
	}
	return count;
}

void CGraph::dispose()
{
	disposeMatrix();
	disposeEdges();
}

void CGraph::disposeev()
{
	if (_evmat != nullptr)
	{
		delete[] _evmat;
		_evmat = nullptr;
	}
}

void CGraph::disposeMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::disposeEdges()
{
	if (_edge != nullptr)
	{
		delete[] _edge;
		_edge = nullptr;
	}
}

void CGraph::initEdgesFromMatrix()
{
	disposeEdges();
	_edges = getEdgesCountFromMatrix();
	initEdges();
	for (int i = 0, k = 0; i < _vertexes && k < _edges; ++i)
	{
		for (int j = 0; j < _vertexes && k < _edges; ++j)
		{
			if (_matrix[i][j] != 0)
			{
				_edge[k++].set(i + 1, j + 1, _matrix[i][j]);
			}
		}
	}
}

int CGraph::getVertexesCountFromEdges()
{
	int res = 0;
	for (int i = 0; i < _edges; ++i)
	{
		res = (res > _edge[i].a ? res : _edge[i].a);
		res = (res > _edge[i].b ? res : _edge[i].b);
	}
	return res + 1;
}

std::ostream& operator<<(std::ostream& stream, const SEdge& edge)
{
	stream << edge.a << " " << edge.b;
	if (edge.w > 1)
	{
		stream << " " << edge.w;
	}
	return stream;
}

void CGraph::Readev(std::istream& stream)
{
	_evmat = new int[3];
	for (int i = 0; i < 3; ++i)
	{
		stream >> _evmat[i];
	}

}

void CGraph::task5()
{
	while (_evmat[1] != _evmat[2]) {
		if (_evmat[1] > _evmat[2]) {
			_evmat[1] /= 2;
		}
		else {
			_evmat[2] /= 2;
		}
	}

	std::cout << _evmat[1];
	disposeev();
}
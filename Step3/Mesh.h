#pragma once

#include <vector>

#include "graphics/GrVector.h"
#include "graphics/GrTexture.h"

class CMesh
{
public:
    CMesh(void);
    virtual ~CMesh(void);

    void Draw();

    void AddVertex(const CGrVector &v) {m_vertices.push_back(v);}
    void AddNormal(const CGrVector &n) {m_normals.push_back(n);}
    void AddTexCoord(const CGrVector &t) {m_tvertices.push_back(t);}
    void AddTriangleVertex(int v, int n, int t);
	void SetTexture(CGrTexture *texture) {m_texture = texture;}
	CGrTexture *GetTexture() {return m_texture;}
	//void SetLightAngle(CGrVector a) {lightAngle = a;}
	void ReadFile();

private:
    std::vector<CGrVector> m_vertices;
    std::vector<CGrVector> m_normals;
    std::vector<CGrVector> m_tvertices;

    // A triangle vertex description
    struct TV
    {
        int     v;      // Vertex
        int     n;      // Normal
        int     t;      // Texture coordinate
    };

    typedef std::vector<TV> Triangles;
    typedef Triangles::iterator PTV;
    Triangles       m_triangles;
	CGrTexture *m_texture;  // Texture to use for the mesh

	typedef struct tagMATRIX
    {
	    float Data[16];
    }
    MATRIX;

	GLuint shaderTexture[1];
	float red;
	float green;
	float blue;
public:
	void AddFlatQuad(int a, int b, int c, int d, int n);
	void AddQuad(int a, int b, int c, int d);
	void ComputeSmoothNormals(void);
	void LoadOBJ(const char * filename);
	void RotateVector(MATRIX &M, CGrVector &v, CGrVector &d);
	void SetShaderColor(float r, float g, float b) {red = r; green = g; blue = b;}
};



//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_HPP
#define MT_MATRIX_HPP

//////////////////////////////////////////////////////////////////////////

#include "Creator.hpp"
#include "Vertex.hpp"

//////////////////////////////////////////////////////////////////////////

#define MT_GRAPH_MATRIX_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

//namespace Masters::Matrix
//{
//	class CMatrix : CSizes
//	{
//	private: // typedefs
//		using ULine = std::vector<Matrix::CVertex>;
//		using UMatrix = std::vector<ULine>;
//
//	public: // ctor
//		CMatrix() : m_matrix() {}
//		CMatrix(const Matrix::CHeight height, const Matrix::CLength& length, const Matrix::CVertex defVertex) :
//			m_matrix(height.value(), ULine(length.value(), defVertex)) {}
//
//		CMatrix(const Matrix::CCreator& creator) :
//			CMatrix(creator.height(), creator.length(), creator.defaultVertex())
//		{
//			const auto& vcList = creator.veretexCreatorList();
//			for (const auto& node : vcList)
//			{
//				if (!Matrix::Location::isValidLoc(node.location(), creator))
//				{
//					/*temp, exception*/
//					throw std::string("Matrix::Matrix(Creator), Location is not valid (node.location(), properties))");
//				}
//
//				Matrix::CVertex& vertex = at(node.location());
//				vertex.condition(node.condition());
//			}
//
//			//temp, only auto 
//			Matrix::CNManager manager;
//			manager.make<Matrix::CNManagerAuto>();
//
//
//			///*is graph directed*/
//			//if (creator.propertyies().direction() == Matrix::EDirection::Directed)
//			//{
//			//	manager.make<Matrix::CNManagerManual>();
//			//}
//			//else
//			//{
//			//	manager.make<Matrix::CNManagerAuto>();
//			//}
//			//if (manager == nullptr)
//			//{
//			//	throw std::string("Matrix::Matrix(Creator), manager is nullptr");
//			//}
//
//
//			for (const auto& node : vcList)
//			{
//				Matrix::CVertex& vertex = at(node.location());
//				manager.createNList(*this/*Sizes*/, vertex);
//			}
//		}
//
//	public: // operators
//		Matrix::CVertex& operator[](const Matrix::CLocation& loc) 
//		{
//			if (!Location::isValidLoc(loc, *this))
//			{
//				throw (std::string("Matrix::operator[], loc is not valid"));
//			}
//			return (m_matrix[loc.ordinate().value()][loc.abscissa().value()]);
//		}
//
//	public: // methods
//		Matrix::CVertex& at(const Matrix::CLocation& loc)
//		{
//			return (m_matrix[loc.ordinate().value()][loc.abscissa().value()]);
//		}
//
//
//	private:
//		UMatrix m_matrix;
//	};
//
//	//LeeSimulator()
//	//{
//	//	CCreator creator(...);
//	//	CMatrix graph(creator);
//
//	//	graph.setStartEndLoc(CStartEnd/*class CStartEnd : std::pair<CStartLoc, CEndLoc>*/);
//	//	// if start end vertices not valid except
//
//	//	CLoc startLoc = graph.getStartLoc();
//	//	while (startLoc != NullLoc)
//	//	{
//	//		/*class CNeighborhoods : std::vector<Neighborhood> // class Neighborhood : CLoc */
//	//		CNeighborhoods neighborhoods = startLoc.getNeighborhoods(/*if directed logic1, else logic 2*/);
//	//		for (const CLoc& loc : neighborhoods)
//	//		{
//	//			...
//	//		}
//	//	}
//	//}
//}
//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_HPP

//////////////////////////////////////////////////////////////////////////

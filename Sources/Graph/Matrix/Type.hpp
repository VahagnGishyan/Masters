
//////////////////////////////////////////////////////////////////////////

#ifndef MT_MATRIX_TYPE_HPP
#define MT_MATRIX_TYPE_HPP

//////////////////////////////////////////////////////////////////////////

#define MT_MATRIX_TYPE_EXPORT MASTERS_EXPORT

//////////////////////////////////////////////////////////////////////////

namespace Masters
{
	namespace Graph
	{
		namespace Matrix
		{
			namespace Type
			{
				enum class EDirection
				{
					Directed,
					Undirected
				};

				enum class EWeighing
				{
					Weighted,  // positive weighted 
					NegWeighted, // negativ weighted 
					UnWeighted,  // unweighted 
				};
			}

			struct SType final /*CSmart struct*/
			{
			private:
				using EDirection = Type::EDirection;
				using EWeighing  = Type::EWeighing;

			public: // ctor dector
				SType(const EDirection dir, const EWeighing weigh) : m_dir(dir), m_weigh(weigh) {}
				~SType() {}

			public: // get set
				EDirection direction()                const noexcept { return (m_dir); }
				EWeighing  weighing()                 const noexcept { return (m_weigh); }

				void       direction(const EDirection dir)  noexcept { m_dir = dir; }
				void       weighing(const EWeighing weigh) noexcept { m_weigh = weigh; }

			private: // members
				EDirection m_dir;
				EWeighing  m_weigh;
			};
		}
	}
}

//////////////////////////////////////////////////////////////////////////

#endif // !MT_MATRIX_TYPE_HPP

//////////////////////////////////////////////////////////////////////////


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
				SType(const EDirection dir, const EWeighing weigh);
				~SType();

			public: // get set
				EDirection direction()                const noexcept;
				EWeighing  weighing()                 const noexcept;

				void       direction(const EDirection dir)  noexcept;
				void       weighing(const EWeighing weigh)  noexcept;

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

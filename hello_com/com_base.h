
#ifndef PLCOM_EXPORT
# define DLLAPI extern"C" __declspec(dllimport)
#else
# define DLLAPI extern"C" __declspec(dllexport)

template<typename T,typename T2>
T static_cast_set(T& dest, const T2& serc){
	return dest= static_cast<T>(serc);
}

#endif

class object{};
#pragma once

#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

namespace libftpp {
namespace meta {
	namespace detail {
		template <typename T>
		struct TypeName {
			static std::string get() { return "unknown"; }
		};

		template <typename T>
		struct TypeName<std::vector<T> > {
			static std::string get() { return "std::vector<" + TypeName<T>::get() + ">"; }
		};

		template <typename T>
		struct TypeName<std::deque<T> > {
			static std::string get() { return "std::deque<" + TypeName<T>::get() + ">"; }
		};

		template <typename T>
		struct TypeName<std::list<T> > {
			static std::string get() { return "std::list<" + TypeName<T>::get() + ">"; }
		};

		template <typename T>
		struct TypeName<std::set<T> > {
			static std::string get() { return "std::set<" + TypeName<T>::get() + ">"; }
		};

		template <typename T>
		struct TypeName<std::multiset<T> > {
			static std::string get() { return "std::multiset<" + TypeName<T>::get() + ">"; }
		};

		template <typename Key, typename Value>
		struct TypeName<std::pair<Key, Value> > {
			static std::string get() { return "std::pair<" + TypeName<Key>::get() + ", " + TypeName<Value>::get() + ">"; }
		};

		template <typename Key, typename Value>
		struct TypeName<std::map<Key, Value> > {
			static std::string get() { return "std::map<" + TypeName<Key>::get() + ", " + TypeName<Value>::get() + ">"; }
		};

		template <typename Key, typename Value>
		struct TypeName<std::multimap<Key, Value> > {
			static std::string get() { return "std::multimap<" + TypeName<Key>::get() + ", " + TypeName<Value>::get() + ">"; }
		};

		template <typename T, typename Container>
		struct TypeName<std::stack<T, Container> > {
			static std::string get() { return "std::stack<" + TypeName<T>::get() + ">"; }
		};

		template <typename T, typename Container>
		struct TypeName<std::queue<T, Container> > {
			static std::string get() { return "std::queue<" + TypeName<T>::get() + ">"; }
		};

		template <typename T, typename Container, typename Compare>
		struct TypeName<std::priority_queue<T, Container, Compare> > {
			static std::string get() { return "std::priority_queue<" + TypeName<T>::get() + ">"; }
		};

		template <>
		struct TypeName<std::string> {
			static std::string get() { return "std::string"; }
		};

		template <>
		struct TypeName<bool> { static std::string get() { return "bool"; } };
		template <>
		struct TypeName<char> { static std::string get() { return "char"; } };
		template <>
		struct TypeName<signed char> { static std::string get() { return "signed char"; } };
		template <>
		struct TypeName<unsigned char> { static std::string get() { return "unsigned char"; } };
		template <>
		struct TypeName<short> { static std::string get() { return "short"; } };
		template <>
		struct TypeName<unsigned short> { static std::string get() { return "unsigned short"; } };
		template <>
		struct TypeName<int> { static std::string get() { return "int"; } };
		template <>
		struct TypeName<unsigned int> { static std::string get() { return "unsigned int"; } };
		template <>
		struct TypeName<long> { static std::string get() { return "long"; } };
		template <>
		struct TypeName<unsigned long> { static std::string get() { return "unsigned long"; } };
		template <>
		struct TypeName<float> { static std::string get() { return "float"; } };
		template <>
		struct TypeName<double> { static std::string get() { return "double"; } };
		template <>
		struct TypeName<long double> { static std::string get() { return "long double"; } };
	}

	class TypeInspector {
	private:
		TypeInspector();
		TypeInspector(const TypeInspector&);
		TypeInspector& operator=(const TypeInspector&);
		~TypeInspector();

		static bool convert_from_string(const std::string& input, std::string& output);
		template <typename To>
		static bool convert_from_string(const std::string& input, To& output) {
			std::istringstream stream(input);
			stream >> output;
			return stream.good() || (stream.eof() && !stream.fail());
		}

		template <typename From>
		static bool convert_to_string(const From& input, std::string& output) {
			std::ostringstream stream;
			stream << input;
			if (stream.fail())
				return false;
			output = stream.str();
			return true;
		}

	public:
		template <typename T>
		static std::string name() {
			return detail::TypeName<T>::get();
		}

		template <typename T>
		static std::string name(const T&) {
			return name<T>();
		}

		template <typename T>
		static std::string name(const std::vector<T>&) {
			return detail::TypeName<std::vector<T> >::get();
		}

		template <typename T>
		static std::string name(const std::deque<T>&) {
			return detail::TypeName<std::deque<T> >::get();
		}

		template <typename T>
		static std::string name(const std::list<T>&) {
			return detail::TypeName<std::list<T> >::get();
		}

		template <typename T>
		static std::string name(const std::set<T>&) {
			return detail::TypeName<std::set<T> >::get();
		}

		template <typename T>
		static std::string name(const std::multiset<T>&) {
			return detail::TypeName<std::multiset<T> >::get();
		}

		template <typename Key, typename Value>
		static std::string name(const std::map<Key, Value>&) {
			return detail::TypeName<std::map<Key, Value> >::get();
		}

		template <typename Key, typename Value>
		static std::string name(const std::multimap<Key, Value>&) {
			return detail::TypeName<std::multimap<Key, Value> >::get();
		}

		template <typename T, typename Container>
		static std::string name(const std::stack<T, Container>&) {
			return detail::TypeName<std::stack<T, Container> >::get();
		}

		template <typename T, typename Container>
		static std::string name(const std::queue<T, Container>&) {
			return detail::TypeName<std::queue<T, Container> >::get();
		}

		template <typename T, typename Container, typename Compare>
		static std::string name(const std::priority_queue<T, Container, Compare>&) {
			return detail::TypeName<std::priority_queue<T, Container, Compare> >::get();
		}

		static bool convert(const std::string& input, std::string& output);
		static bool convert(const std::string& input, bool& output);
		static bool convert(bool input, std::string& output);
		static bool convert(bool input, bool& output);

		template <typename To>
		static bool convert(const std::string& input, To& output) {
			return convert_from_string(input, output);
		}

		template <typename From>
		static bool convert(const From& input, std::string& output) {
			return convert_to_string(input, output);
		}

		template <typename To, typename From>
		static bool convert(const From& input, To& output) {
			std::string buffer;
			if (!convert_to_string(input, buffer))
				return false;
			return convert_from_string(buffer, output);
		}
	};

	inline bool TypeInspector::convert_from_string(const std::string& input, std::string& output) {
		output = input;
		return true;
	}

	inline bool TypeInspector::convert(const std::string& input, std::string& output) {
		return convert_from_string(input, output);
	}

	inline bool TypeInspector::convert(const std::string& input, bool& output) {
		if (input == "1" || input == "true") {
			output = true;
			return true;
		}
		if (input == "0" || input == "false") {
			output = false;
			return true;
		}
		return false;
	}

	inline bool TypeInspector::convert(bool input, std::string& output) {
		output = input ? "true" : "false";
		return true;
	}

	inline bool TypeInspector::convert(bool input, bool& output) {
		output = input;
		return true;
	}
}
}
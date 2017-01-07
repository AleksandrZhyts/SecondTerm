#pragma once

#include "stdafx.h"

namespace snap {

	struct base_handle {
		typedef base_handle* pbase_handle;

		static const size_t max = 40;

		HANDLE pid;
		std::wstring name;

		pbase_handle _left, _rigth;

		base_handle() : _left(nullptr), _rigth(nullptr) {};

		void operator << (base_handle& element) {
			this->_left = &element;
		}
		void operator << (const pbase_handle& element) {
			this->_left = element;
		}
		void operator >> (base_handle& element) {
			this->_rigth = &element;
		}
		void operator >> (const pbase_handle& element) {
			this->_rigth = element;
		}
		void operator() (char *buffer) {
			std::string str = buffer;
			std::wstring wstr(str.begin(), str.end());
			name = wstr;
		}
		void operator() (wchar_t *buffer) {
			name = buffer;
		}
		void operator() (std::string& str) {
			std::wstring wstr(str.begin(), str.end());
			name = wstr;
		}
	};

	template <class T>
	struct handle_vector : private vector<T> {
		handle_vector() : _max(base_handle::max) {
			this->reserve(base_handle::max);
		}
		void push_back(T& element) {
			if (this->size() == this->capacity()) {
				_max += 10;
				vector<T>::reserve(_max);
			}
			vector<T>::push_back(element);
		}
		const_reference operator[](size_type _Pos) const {
			return vector<T>::operator[](_Pos);
		}
	private:
		size_t _max;
	};

	template <class T>
	struct custom_tree : private base_handle, handle_vector<T>, binary_tree<base_handle> {
		void add(HANDLE pid, std::wstring name) {
			add(pid, name, nullptr);
		};
		void add(HANDLE pid, std::string name) {
			std::wstring wstr(name.begin(), name.end());
			add(pid, wstr, nullptr);
		};
		void add(HANDLE pid, std::wstring name, handle_vector<T>& elements) {
			base_handle *_new = base_handle();
			_new->name(name);
			_new->pid = pid;
			this->Insert(_new);
		};
	};
}


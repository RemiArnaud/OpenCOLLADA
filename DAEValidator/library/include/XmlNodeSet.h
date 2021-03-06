#pragma once

#include "libxml/xpath.h"

namespace opencollada
{
    class XmlNode;
    
	class XmlNodeSet
	{
		friend class XmlNode;
	public:
		XmlNodeSet() = default;
		XmlNodeSet(XmlNodeSet&& other);
		~XmlNodeSet();

		const XmlNodeSet & operator = (XmlNodeSet && other);

		class iterator
		{
			friend class XmlNodeSet;
		public:
			XmlNode operator*() const;
			void operator++();
			bool operator != (const iterator & other) const;

		private:
			iterator() = default;
			iterator(xmlNodeSetPtr nodeSet);

		private:
			xmlNodeSetPtr mNodeSet = nullptr;
			int mIndex = 0;
		};

		bool empty() const;
		iterator begin() const;
		iterator end() const;
		size_t size() const;
		XmlNode operator[](int index) const;

	public:
		static XmlNodeSet null;

	private:
		XmlNodeSet(xmlXPathObjectPtr xpathObject);
		XmlNodeSet(const XmlNodeSet&) = delete;
		const XmlNodeSet& operator = (const XmlNodeSet & other) = delete;

	private:
		xmlXPathObjectPtr mXPathObject = nullptr;
	};
}

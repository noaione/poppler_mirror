//========================================================================
//
// StructTreeRoot.h
//
// This file is licensed under the GPLv2 or later
//
// Copyright 2013, 2014 Igalia S.L.
// Copyright 2018, 2019, 2024, 2025 Albert Astals Cid <aacid@kde.org>
// Copyright 2018 Adrian Johnson <ajohnson@redneon.com>
// Copyright 2018 Adam Reichold <adam.reichold@t-online.de>
//
//========================================================================

#ifndef STRUCTTREEROOT_H
#define STRUCTTREEROOT_H

#include "Object.h"
#include "StructElement.h"
#include <map>
#include <vector>
#include <memory>

class Dict;
class PDFDoc;

class POPPLER_PRIVATE_EXPORT StructTreeRoot
{
public:
    StructTreeRoot(PDFDoc *docA, const Dict &rootDict);
    ~StructTreeRoot();

    StructTreeRoot &operator=(const StructTreeRoot &) = delete;
    StructTreeRoot(const StructTreeRoot &) = delete;

    PDFDoc *getDoc() { return doc; }
    Dict *getRoleMap() { return roleMap.isDict() ? roleMap.getDict() : nullptr; }
    Dict *getClassMap() { return classMap.isDict() ? classMap.getDict() : nullptr; }
    unsigned getNumChildren() const { return elements.size(); }
    const StructElement *getChild(int i) const { return elements.at(i).get(); }

private:
    // Structure for items in /ParentTree, it keeps a mapping of
    // object references and pointers to StructElement objects.
    struct Parent
    {
        Ref ref = Ref::INVALID();
        StructElement *element = nullptr;
    };

    PDFDoc *doc;
    Object roleMap;
    Object classMap;
    std::vector<std::unique_ptr<StructElement>> elements;
    std::map<int, std::vector<Parent>> parentTree;
    std::multimap<Ref, Parent *> refToParentMap;

    void parse(const Dict &rootDict);
    void parseNumberTreeNode(const Dict &node);
    void parentTreeAdd(const Ref objectRef, StructElement *element);

    void appendChild(std::unique_ptr<StructElement> element)
    {
        if (element && element->isOk()) {
            elements.push_back(std::move(element));
        }
    }

    friend class StructElement;
};

#endif

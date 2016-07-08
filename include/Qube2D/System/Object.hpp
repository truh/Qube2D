///////////////////////////////////////////////////////////////////////////////////
//
//
//                    ___        _            ____  ____
//                   / _ \ _   _| |__   ___  |___ \|  _ \
//                  | | | | | | | '_ \ / _ \   __) | | | |
//                  | |_| | |_| | |_) |  __/  / __/| |_| |
//                   \__\_\\__,_|_.__/ \___| |_____|____/
//
//
//
//  Easy to use cross-platform 2D game engine written in C++, using the OpenGL API.
//  Copyright (C) 2016 Nicolas Kogler (kogler.cml@hotmail.com)
//
//  This file is part of Qube2D.
//
//  Qube2D is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Qube2D is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with Qube2D. If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef __Q2D_OBJECT_HPP__
#define __Q2D_OBJECT_HPP__


///////////////////////////////////////////////////////////
// Included files
//
///////////////////////////////////////////////////////////
#include <Qube2D/Config.hpp>
#include <Qube2D/System/Storage/Variant.hpp>
#include <vector>
#include <map>


namespace Qube2D
{
    ///////////////////////////////////////////////////////////
    /// \file    Object.hpp
    /// \author  Nicolas Kogler (kogler.cml@hotmail.com)
    /// \date    July 5th, 2016
    /// \class   Object
    /// \brief   Base class for all game components.
    ///
    /// The object can hold multiple child objects, dynamic
    /// properties which can hold various value types through
    /// Qube2D::Variant and an unique name identifier.
    ///
    ///////////////////////////////////////////////////////////
    class Q2D_API Object
    {

    public:

        ///////////////////////////////////////////////////////////
        /// \fn     Default constructor
        /// \brief  Initializes a new instance of Qube2D::Object.
        /// \param  parent Parental object or NULL if no parent
        ///
        ///////////////////////////////////////////////////////////
        Object(Object *parent = NULL);

        ///////////////////////////////////////////////////////////
        /// \fn     Destructor -> virtual
        /// \brief  Destructs the devired object.
        ///
        /// This function is virtual so that an object can also be
        /// destroyed if only the base class pointer is available.
        ///
        ///////////////////////////////////////////////////////////
        virtual ~Object();


        ///////////////////////////////////////////////////////////
        /// \fn      parent -> const
        /// \brief   Retrieves a pointer to the parental object.
        ///
        /// In order to determine if the parent is a specific type,
        /// use Object::isType(T).
        ///
        /// \returns a pointer to the base parent object.
        /// \see     children, isType
        ///
        ///////////////////////////////////////////////////////////
        Object *parent() const;

        ///////////////////////////////////////////////////////////
        /// \fn      children -> const
        /// \brief   Retrieves all children of this object.
        /// \returns a constant list of child objects.
        /// \see     childrenOfType, childrenOfName
        ///
        ///////////////////////////////////////////////////////////
        const std::vector<Object *> &children() const;

        ///////////////////////////////////////////////////////////
        /// \fn      name -> const
        /// \brief   Retrieves the name of this object.
        /// \returns NULL if no name has been registered yet.
        ///
        ///////////////////////////////////////////////////////////
        const char *name() const;

        ///////////////////////////////////////////////////////////
        /// \fn     childrenOfType -> const
        /// \brief  Retrieves all children of specified type.
        ///
        /// Attempts to convert each child into an object of the
        /// specified type. If this operation is successful, it
        /// is added to a list which will then be returned.
        /// Usage: auto list = obj.childrenOfType<Type>();
        ///
        /// \returns a list of objects of type T.
        ///
        ///////////////////////////////////////////////////////////
        template <typename T>
        const std::vector<T *> childrenOfType() const;

        ///////////////////////////////////////////////////////////
        /// \fn      childrenOfName -> const
        /// \brief   Retrieves all children matching the given name.
        ///
        /// Iterates through all children and determines whether
        /// their name equals the given value or starts with the
        /// given value.
        ///
        /// \returns a list of objects that match the name.
        ///
        ///////////////////////////////////////////////////////////
        const std::vector<Object *> childrenOfName(const char *name) const;

        ///////////////////////////////////////////////////////////
        /// \fn      isType -> const
        /// \brief   Determines whether this object is type T.
        /// \returns false if this is not a base of T.
        ///
        ///////////////////////////////////////////////////////////
        template <typename T> bool isType() const;

        ///////////////////////////////////////////////////////////
        /// \fn      convert -> const
        /// \brief   Attempts to convert this object to T.
        ///
        /// Attempts to convert this object to given type T. If
        /// successful, returns a pointer to an object of type T.
        /// If not, returns a null pointer.
        /// Usage: Devired *dev = obj.isType<Devired>();
        ///
        /// \returns NULL if this is not T or a base of T.
        ///
        ///////////////////////////////////////////////////////////
        template <typename T> T *convert() const;

        ///////////////////////////////////////////////////////////
        /// \fn      property -> const
        /// \brief   Retrieves the value of a dynamic property.
        ///
        /// Attempts to retrieve the property that was registered
        /// with the given string. If there is no such property,
        /// an invalid Qube2D::Variant will be returned. It is
        /// recommended to check against 'Variant::isValid'.
        ///
        /// \returns the associated value to the property.
        ///
        ///////////////////////////////////////////////////////////
        const Variant &property(const char *name) const;


        ///////////////////////////////////////////////////////////
        /// \fn     setParent
        /// \brief  Specifies the new parent of this object.
        ///
        /// NULL indicates that this object is parentless.
        ///
        /// \param  parent New parent of the object
        ///
        ///////////////////////////////////////////////////////////
        void setParent(Object *parent);

        ///////////////////////////////////////////////////////////
        /// \fn     addChild
        /// \brief  Adds the given Qube2D::Object to the children.
        /// \param  child New child of the object
        ///
        ///////////////////////////////////////////////////////////
        void addChild(Object *child);

        ///////////////////////////////////////////////////////////
        /// \fn     addChildren
        /// \brief  Adds multiple children to this object.
        /// \param  children Collection of children
        ///
        ///////////////////////////////////////////////////////////
        void addChildren(const std::vector<Object *> &children);

        ///////////////////////////////////////////////////////////
        /// \fn     removeChild
        /// \brief  Removes the given object from the children.
        /// \param  child Child to remove
        ///
        ///////////////////////////////////////////////////////////
        void removeChild(const Object *child);

        ///////////////////////////////////////////////////////////
        /// \fn     removeChild
        /// \brief  Removes the object at the given index.
        /// \param  index Index of the child to remove
        ///
        ///////////////////////////////////////////////////////////
        void removeChild(QUInt32 index);

        ///////////////////////////////////////////////////////////
        /// \fn     removeChildren
        /// \brief  Removes multiple children from this object.
        /// \param  children Collection of children to remove
        ///
        ///////////////////////////////////////////////////////////
        void removeChildren(const std::vector<Object *> &children);

        ///////////////////////////////////////////////////////////
        /// \fn     setName
        /// \brief  Gives the object an unique name.
        /// \param  name New name of the object
        ///
        ///////////////////////////////////////////////////////////
        void setName(const char *name);

        ///////////////////////////////////////////////////////////
        /// \fn     setProperty
        /// \brief  Assigns a value to a name-based property.
        ///
        /// This function will create a property if it does not
        /// exist yet. It will overwrite the current value of the
        /// property if it already exists.
        ///
        /// \param  name Name of the property to assign a value to
        /// \param  value The variant value to assign
        ///
        ///////////////////////////////////////////////////////////
        void setProperty(const char *name, const Variant &variant);


    private:

        ///////////////////////////////////////////////////////////
        // Class members
        //
        ///////////////////////////////////////////////////////////
        std::string m_Name;
        Object *m_Parent;
        std::vector<Object *> m_Children;
        std::map<const char*, Variant> m_Properties;
        Variant m_InvalidProp;

    };



    ///////////////////////////////////////////////////////////
    template <typename T>
    inline const std::vector<T *> Object::childrenOfType() const
    {
        std::vector<T *> matches;

        for (Object *obj : m_Children)
            if (dynamic_cast<T *>(obj) != NULL)
                matches.push_back(dynamic_cast<T *>(obj));

        return matches;
    }

    ///////////////////////////////////////////////////////////
    template <typename T> inline bool Object::isType() const
    {
        return dynamic_cast<T *>(this) != NULL;
    }

    ///////////////////////////////////////////////////////////
    template <typename T> inline T *Object::convert() const
    {
        return dynamic_cast<T *>(this);
    }
}


#endif  // __Q2D_OBJECT_HPP__

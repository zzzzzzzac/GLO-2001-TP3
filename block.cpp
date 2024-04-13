/**
 * \file block.cpp
 * \brief Implémentation d'un bloc.
 * \author ?
 * \version 0.1
 * \date  2021
 *
 *  Travail pratique numéro 3
 *
 */

#include "block.h"
//vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP3
{
	// Ajouter votre code ici !

    size_t Block::getFirstAvailableInode() {
        for (int i = 0; i < m_bitmap.size(); ++i) {
            if (m_bitmap[i]){
                return i; // retourne l'indice (le numero) du premier i-node libre de la bitmap
            }
        }
        return -1; // si aucun bit n'est disponible
    }

    size_t Block::getFirstAvailableBlock() {
        for (int i = 0; i < m_bitmap.size(); ++i) {
            if (m_bitmap[i]){
                return i; // retourne l'indice (le numero) du premier block libre de la bitmap
            }
        }
        return -1; // si aucun bit n'est disponible
    }


    void Block::createRepository(){
        size_t inodeNumber = getFirstAvailableInode();

        addEntry(m_inode->st_ino, "."); //i-node courant
        addEntry(m_inode->st_ino, ".."); //i-node parent
    }


    void Block::addEntry(size_t i_node, std::string & filename){
        auto entry = new dirEntry(i_node, filename);
        m_dirEntry.push_back(entry);
    }


    bool Block::doesRepositoryExists(size_t iNode){
            // Vérification de l'existence d'un répertoire par i-node
            for (auto entry : m_dirEntry) {
                if (entry->m_iNode == iNode) {
                    return true;
                }
            }
            return false;
        }


    Block::~Block() {
        for (auto entry : m_dirEntry) {
            delete entry;
        }
    }
}//Fin du namespace





<<<<<<< HEAD
/* Copyright (C) 2019 MariaDB Corporation

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; version 2 of
   the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */
=======
# copy licensing stuff here
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.

#include <sys/types.h>
#include "SMFileSystem.h"
#include "SMComm.h"
#include "sm_exceptions.h"

using namespace std;

namespace idbdatafile
{

SMFileSystem::SMFileSystem() : IDBFileSystem(IDBFileSystem::CLOUD)
{
<<<<<<< HEAD
    SMComm::get();   // get SMComm running
}

SMFileSystem::~SMFileSystem()
{
<<<<<<< HEAD
=======
    SMComm::getSMComm();   // get SMComm running
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
=======
>>>>>>> f063f782... Fixed some linker errors, integrated the cloudio factory
}

int SMFileSystem::mkdir(const char *path)
{
    return 0;
}

<<<<<<< HEAD
off64_t SMFileSystem::size(const char *filename) const
=======
int SMFileSystem::size(const char *filename) const
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
{
    struct stat _stat;
    
    SMComm *smComm = SMComm::get();
    int err = smComm->stat(filename, &_stat);
<<<<<<< HEAD
    if (err)
=======
    if (!err)
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
        return err;
    
    return _stat.st_size;
}

off64_t SMFileSystem::compressedSize(const char *filename) const
{
    // Yikes, punting on this one.
    throw NotImplementedYet(__func__);
}

<<<<<<< HEAD
<<<<<<< HEAD
int SMFileSystem::remove(const char *filename)
=======
int SMFileSystem::remove(const char *filename) const
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
=======
int SMFileSystem::remove(const char *filename)
>>>>>>> f063f782... Fixed some linker errors, integrated the cloudio factory
{
    SMComm *comm = SMComm::get();
    return comm->unlink(filename);
}

<<<<<<< HEAD
<<<<<<< HEAD
int SMFileSystem::rename(const char *oldFile, const char *newFile)
{
    int err = copyFile(oldFile, newFile);
    if (err)
        return err;
    err = this->remove(oldFile);
    return err;
=======
int SMFileSystem::rename(const char *oldFile, const char *newFile) const
=======
int SMFileSystem::rename(const char *oldFile, const char *newFile)
>>>>>>> f063f782... Fixed some linker errors, integrated the cloudio factory
{
    // This will actually be pretty expensive to do b/c we store the filename in 
    // the key in cloud.  If we do this a lot, we'll have to implement copy() in the SM.
    throw NotImplementedYet(__func__);
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
}

bool SMFileSystem::exists(const char *filename) const
{
    struct stat _stat;
    SMComm *comm = SMComm::get();
    
    int err = comm->stat(filename, &_stat);
    return (err == 0);
}

int SMFileSystem::listDirectory(const char* pathname, std::list<std::string>& contents) const
{
    SMComm *comm = SMComm::get();
    return comm->listDirectory(pathname, &contents);
}

bool SMFileSystem::isDir(const char *path) const
{
    SMComm *comm = SMComm::get();
    struct stat _stat;
    
<<<<<<< HEAD
    int err = comm->stat(path, &_stat);
    if (err != 0)
        return false;   // reasonable to throw here?  todo, look at what the other classes do.
    return (_stat.st_mode & S_IFDIR);
=======
    int err = comm->stat(path, &stat);
    if (err != 0)
        return false;   // reasonable to throw here?  todo, look at what the other classes do.
    return (stat.st_mode & S_IFDIR);
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
}

int SMFileSystem::copyFile(const char *src, const char *dest) const
{
<<<<<<< HEAD
    SMComm *comm = SMComm::get();
    return comm->copyFile(src, dest);
=======
    throw NotImplementedYet(__func__);
>>>>>>> d53471fc... Checkpointing some stuff.  No way it'll build yet.
}
    
bool SMFileSystem::filesystemIsUp() const
{
    SMComm *comm = SMComm::get();
    return (comm->ping() == 0);
}

}

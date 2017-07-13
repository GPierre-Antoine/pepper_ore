# - Try to find Fcgi++
# Once done, this will define
#
#  Fcgi++_FOUND - system has Fcgi++
#  Fcgi++_INCLUDE_DIRS - the Fcgi++ include directories
#  Fcgi++_LIBRARIES - link these to use Fcgi++

# - Try to find Fcgi++
# Once done, this will define
#
#  FCGI++_FOUND - system has Fcgi++
#  FCGI++_INCLUDE_DIRS - the Fcgi++ include directories
#  FCGI++_LIBRARIES - link these to use Fcgi++

#steps :
# resolve dependency with find_package
#
# resolve path with find_path and find_library
# > save results in _INCLUDE_DIR and _LIBRARY
#
#
#
#
find_package(PkgConfig)

find_path(FCGI++_INCLUDE_DIR fcgi/fcgio.h)
set(FCGI++_INCLUDE_DIR ${FCGI++_INCLUDE_DIR}/fcgi)
find_library(FCGI++_LIBRARY NAMES fcgi++)
find_library(FCGI_LIBRARY NAMES fcgi)
include(FindPackageHandleStandardArgs)
SET(FCGI++_LIBRARIES ${FCGI++_LIBRARY} ${FCGI_LIBRARY})
find_package_handle_standard_args(FCGI++ DEFAULT_MSG FCGI++_LIBRARIES FCGI++_INCLUDE_DIR)
mark_as_advanced(FCGI++_LIBRARY FCGI++_INCLUDE_DIR)

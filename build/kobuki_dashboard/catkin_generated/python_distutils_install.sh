#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/mech-user/enshu_ws/src/kobuki_desktop/kobuki_dashboard"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/mech-user/enshu_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/mech-user/enshu_ws/install/lib/python2.7/dist-packages:/home/mech-user/enshu_ws/build/kobuki_dashboard/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/mech-user/enshu_ws/build/kobuki_dashboard" \
    "/usr/bin/python2" \
    "/home/mech-user/enshu_ws/src/kobuki_desktop/kobuki_dashboard/setup.py" \
     \
    build --build-base "/home/mech-user/enshu_ws/build/kobuki_dashboard" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/mech-user/enshu_ws/install" --install-scripts="/home/mech-user/enshu_ws/install/bin"

#!/bin/sh
set -e

# ---------------------------------------------------------------------------- #
#
# Installs SOLR search server.
#
# ---------------------------------------------------------------------------- #


# No need for Solr if the profile is not installed.
if [ $INSTALL_PROFILE != 1 ]; then
 exit 0;
fi


# We use a script hosted on GitHub.
SCRIPT_URL="https://raw.githubusercontent.com/zero2one/travis-solr/master/travis-solr.sh"
SCRIPT_CONFIG="$TRAVIS_BUILD_DIR/search_api_solr/solr-conf/4.x"

# Define the core name we want.
CORE_NAME="$1"

cd $TRAVIS_BUILD_DIR
drush dl search_api_solr
curl -sSL $SCRIPT_URL | SOLR_CORE="$CORE_NAME" SOLR_CONFS="$SCRIPT_CONFIG" bash
rm -R $TRAVIS_BUILD_DIR/search_api_solr

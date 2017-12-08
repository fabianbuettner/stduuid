// test_win.cpp : Defines the entry point for the console application.
//
#include "..\..\src\uuid.h"
#include <assert.h>

int main()
{
   using namespace uuids;

   {
      uuid empty;
      assert(empty.is_nil());
      assert(empty.size() == 16);
   }

   {
      uuid const guid = uuids::make_uuid();
      assert(!guid.is_nil());
      assert(guid.size() == 16);
      assert(guid.version() == uuids::version_type::random_number_based);
      assert(guid.variant() == uuids::variant_type::rfc);
   }

   {
      uuid empty;
      uuid guid = uuids::make_uuid();

      assert(empty == empty);
      assert(guid == guid);
      assert(empty != guid);
   }

   {
      uuid empty;
      uuid guid = uuids::make_uuid();

      assert(empty.is_nil());
      assert(!guid.is_nil());

      std::swap(empty, guid);

      assert(!empty.is_nil());
      assert(guid.is_nil());

      empty.swap(guid);

      assert(empty.is_nil());
      assert(!guid.is_nil());
   }

   return 0;
}


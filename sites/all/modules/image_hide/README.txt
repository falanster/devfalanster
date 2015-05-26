
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * How to Use
 * Design Decisions


INTRODUCTION
------------

Current Maintainer: neRok

This module provides a check box next to each image on the image field form,
which allows the image to be hidden.

INSTALLATION
------------

As per standard module installation.

  * This module requires Drupal 7.22 at a minimum, as it uses the new function
    field_info_field_map().
  * This module is ineffective with core Image module being enabled.
  * This module works best with modules that show the images in other manors.
    Typically this would be via Insert module (images directly into text).

HOW TO USE
----------------

Once the module is installed, the 'admin' setup is per image field edit form.
For the article node type, with a field 'field_my_images', this would be at;
admin/structure/types/manage/article/fields/field_my_images

The options are;
  * Disabled (default)
    This module does not act upon the field.
  * Enabled - Image VISIBLE by default
    This module will act upon this field.
    New images add to the field will be visible by default.
  * Enabled - Image HIDDEN by default
    This module will act upon this field.
    New images added to the field will be hidden by default.
    
If the module is enabled for the image field, when editing the entity
(eg node/%/edit), an option box will be presented next to each image.
Ticking the option will hide the image from the fields display.
The option is per image.

DESIGN DECISIONS
----------------

1.  There is no hook_shema_field_alter() as of Drupal 7.22.
    Instead, this module stores its information with the image file itself,
    in the {file_managed} table.
    
2.  This module does not have a 'batch' update feature.
    When the module is enabled, all images are set to 'shown' in the database.
    When uninstalling the module, the hide/show information is deleted.
    The default hide/show on the field edit form works purely for new images.
    A batch update feature could be inegrated from File (Field) Paths module,
    which has similar code underpinnings.

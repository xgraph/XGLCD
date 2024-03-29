/**
 * Create images to test their functionalities
 */

#include "lv_xg.h"
#include "lvgl.h"

LV_IMG_DECLARE(img_flower_icon);

void setup() {
  Serial.begin(38400);                                                        // Debugging info via Arduino Terminal = Serial debugging port

  lv_xg_init();                                                               // Init X-Graph LCD, LittleVGL library and the LittleVGL to X-Graph driver
  
  /*Create an image object from a varibale*/
  lv_obj_t * img1 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img1, &img_flower_icon);
  lv_obj_set_pos(img1, 10, 10);

  /*Copy the previous image and set a redish style*/
  static lv_style_t style;
  lv_style_copy(&style, &lv_style_plain);
  style.image.color = LV_COLOR_RED;
  style.image.intense = LV_OPA_70;

  lv_obj_t * img2 = lv_img_create(lv_scr_act(), img1);
  lv_img_set_style(img2, &style);
  lv_obj_align(img2, img1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);

  /*Copy the previous image and test the mosaic feature*/
  lv_obj_t * img3 = lv_img_create(lv_scr_act(), img2);
  lv_obj_set_size(img3, 100, 100);
  lv_obj_align(img3, img2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);

  /*Test symbol drawing*/
  lv_obj_t * img4 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img4, SYMBOL_SETTINGS SYMBOL_OK);
  lv_obj_align(img4, img3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);
}

void loop() {
  lv_task_handler();                                                          // Handle the GUI
  delay(5);                                                                   // Just wait a little
}

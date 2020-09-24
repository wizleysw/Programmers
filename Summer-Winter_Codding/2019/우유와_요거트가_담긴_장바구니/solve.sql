SELECT DISTINCT mc.CART_ID FROM CART_PRODUCTS AS mc JOIN CART_PRODUCTS AS yc ON mc.CART_ID = yc.CART_ID AND mc.NAME LIKE "Milk" AND yc.NAME LIKE "Yogurt" ORDER BY mc.CART_ID
